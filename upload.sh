#!/bin/sh

expected_board="$1"
project="$2"

echo "🔍 Detecting connected Arduino board..."
output="$(arduino-cli board list | grep Arduino)"
if [ -z "$output" ]; then
    echo "❌ ERROR: No Arduino board connected." >&2
    exit 1
fi

device="$(echo "$output" | awk '{print $1}')"
detected_board="$(echo "$output" | awk '{print $(NF-1)}')"

echo "✅ Found device: $device"
echo "✅ Found board: $detected_board"

if [ "$detected_board" != "$expected_board" ]; then
    echo "⚠️  Won't upload: expected $expected_board, but found $detected_board"
    exit 2
fi

echo "🚀 Uploading $project to $device using board $expected_board..."
arduino-cli upload -b "$expected_board" -p "$device" "$project"
