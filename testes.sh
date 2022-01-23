#!/bin/bash

echo "The series of filenames are:"

# Generate five filenames with the extension 'png'
for name in seq(3); do
    ./testesEnunciado$name.txt
done