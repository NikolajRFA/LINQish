#!/bin/bash
set -e

JSON_FILE="library.json"
PROPERTIES_FILE="library.properties"

declare -A mappings=(
  ["version"]="version"
  ["name"]="name"
  ["license"]="license"
  ["repository.url"]="repository"
  ["description"]="paragraph"
)

discrepancies=()

for json_key in "${!mappings[@]}"; do
  prop_key="${mappings[$json_key]}"
  json_value=$(jq -r ".${json_key}" "$JSON_FILE")
  prop_value=$(grep -E "^$prop_key=" "$PROPERTIES_FILE" | cut -d'=' -f2)

  if [ "$json_value" != "$prop_value" ]; then
    discrepancies+=("Mismatch in $prop_key:
  - library.json: $json_value
  - library.properties: $prop_value")
  fi
done

if [ "${#discrepancies[@]}" -eq 0 ]; then
  echo "All keypairs match between library.json and library.properties"
  exit 0
else
  echo "Detected the following discrepancies:"
  printf "%s\n\n" "${discrepancies[@]}"
  exit 1
fi
