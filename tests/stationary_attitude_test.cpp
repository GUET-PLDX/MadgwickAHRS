#include <cassert>
#include <cmath>
#include <limits>

#include "../MadgwickAHRS.hpp"

int main() {
  float s0 = 0.0f;
  float s1 = 0.0f;
  float s2 = 0.0f;
  float s3 = 0.0f;
  assert(!MadgwickAHRSDetail::NormalizeGradient(s0, s1, s2, s3));
  assert(s0 == 0.0f && s1 == 0.0f && s2 == 0.0f && s3 == 0.0f);

  s0 = 3.0f;
  s1 = 4.0f;
  assert(MadgwickAHRSDetail::NormalizeGradient(s0, s1, s2, s3));
  assert(std::abs(s0 - 0.6f) < 1e-6f);
  assert(std::abs(s1 - 0.8f) < 1e-6f);

  s0 = std::numeric_limits<float>::infinity();
  assert(!MadgwickAHRSDetail::NormalizeGradient(s0, s1, s2, s3));
}
