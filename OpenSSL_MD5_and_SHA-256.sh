#!/bin/bash

echo "MD5"
openssl md5 file1.pdf
openssl md5 file2.pdf

echo ""
echo "SHA-256"
openssl sha256 file1.pdf
openssl sha256 file2.pdf
