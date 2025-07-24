#!/bin/bash
set -e

expected_header='Copyright (c) 2025-present Nikolaj Andersen'
file_extensions=("*.cpp" "*.hpp" "*.h" "*.c" "*.ino")
missing_files=()

for ext in "${file_extensions[@]}"; do
  while IFS= read -r -d '' file; do
    if ! grep -Fq "$expected_header" "$file"; then
      missing_files+=("$file")
    fi
  done < <(find . -type d -name .pio -prune -o -type f -name "$ext" -print0)
done

if [ ${#missing_files[@]} -gt 0 ]; then
  echo "The following files are missing the required license header:"
  for file in "${missing_files[@]}"; do
    echo "  - $file"
  done
  exit 1
else
  echo "All checked files include the license header."
fi
