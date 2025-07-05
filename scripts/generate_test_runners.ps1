param (
    [Parameter(Mandatory = $true)]
    [string]$SharedTestPath
)

# 🧩 Step 1: Extract method name from shared test path
# Example: "test/shared/filter_tests.h" → "filter"
$FileName = [System.IO.Path]::GetFileNameWithoutExtension($SharedTestPath)
$MethodName = $FileName -replace "_tests$", ""

# 🗂 Step 2: Define output paths
$EmbeddedDir = "test/embedded/test_$MethodName"
$NativeDir = "test/native/test_$MethodName"
$EmbeddedFile = "$EmbeddedDir/${MethodName}_tests.cpp"
$NativeFile = "$NativeDir/${MethodName}_tests.cpp"

# 📁 Step 3: Ensure directories exist
New-Item -ItemType Directory -Path $EmbeddedDir -Force | Out-Null
New-Item -ItemType Directory -Path $NativeDir -Force | Out-Null

# 📝 Step 4: Create embedded test runner content
$EmbeddedContent = @"
/*
 Copyright (c) 2025-present Nikolaj Andersen

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

    https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
**/

//
// Auto-generated embedded test runner
//
#include "Arduino.h"
#include "../../shared/${MethodName}_tests.h"

void setup()
{
    delay(2000);
    runUnityTests();
}

void loop() {}
"@

# 📝 Step 5: Create native test runner content
$NativeContent = @"
/*
 Copyright (c) 2025-present Nikolaj Andersen

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

    https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
**/

//
// Auto-generated native test runner
//
#include "../../shared/${MethodName}_tests.h"

int main()
{
    return runUnityTests();
}
"@

# 💾 Step 6: Write files
Set-Content -Path $EmbeddedFile -Value $EmbeddedContent -Encoding UTF8
Set-Content -Path $NativeFile -Value $NativeContent -Encoding UTF8
