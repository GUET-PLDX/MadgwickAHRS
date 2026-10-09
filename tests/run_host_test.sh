#!/usr/bin/env bash
set -euo pipefail
test_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
module_root="$(cd "$test_dir/../.." && pwd)"
libxr="$module_root/../Middlewares/Third_Party/LibXR"
includes=()
while IFS= read -r -d '' path; do includes+=(-isystem "$path"); done < <(find "$libxr/src" -type d -print0)
"${CXX:-c++}" -std=c++20 -Wall -Wextra -Werror \
  -DLIBXR_DEFAULT_SCALAR=float -DXR_LOG_MESSAGE_MAX_LEN=128 \
  -isystem "$libxr/system/linux" -isystem "$libxr/lib/Eigen" \
  "${includes[@]}" "$test_dir/stationary_attitude_test.cpp" \
  -o /tmp/madgwick_stationary_attitude_test
/tmp/madgwick_stationary_attitude_test
