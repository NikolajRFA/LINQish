#!/bin/bash
set -e

JSON_FILE="library.json"
PROPERTIES_FILE="library.properties"

# Extract version from library.json
json_version=$(jq -r '.version' "$JSON_FILE")

# Extract version from library.properties
properties_version=$(grep -E '^version=' "$PROPERTIES_FILE" | cut -d'=' -f2)

# Compare
if [ "$json_version" == "$properties_version" ]; then
    echo "Version match: $json_version"
    exit 0
else
    echo "Version mismatch:"
    echo "  - library.json: $json_version"
    echo "  - library.properties: $properties_version"
    exit 1
fi
