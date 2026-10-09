#!/usr/bin/env python3
"""Guard the zero-gradient case for a level, stationary IMU."""

import re
from pathlib import Path


source = (Path(__file__).resolve().parents[1] / "MadgwickAHRS.hpp").read_text()
step = source.split("/* Gradient decent algorithm corrective step */", 1)[1]
step = step.split("/* Integrate rate of change", 1)[0]

# At identity orientation with acceleration (0, 0, 1), s0..s3 are all zero.
guard = re.search(r"if\s*\(MadgwickAHRSDetail::NormalizeGradient\(s0, s1, s2, s3\)\)\s*\{", step)
assert guard, "stationary zero gradient must skip feedback"
assert step.find("}", guard.end()) > step.find("q_dot4 -=", guard.end()), "feedback must remain inside the gradient guard"
print("PASS: stationary attitude gradient guard")
