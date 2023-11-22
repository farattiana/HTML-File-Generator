# HTML FILE GENERATOR

## Overview 

The HTML File Generator in C is a tool designed to simplify the process of creating a basic directory structure for HTML, CSS, and JS files using the C programming language. This tool enables users to swiftly generate a project's web structure without the need to manually create each file. It operates specifically within the project's base directory, generating the HTML structure along with CSS and JS files.

## Prerequisites
Before using this project, ensure you have the following:

**1.Clone the repository:** Use the `git clone` command or download the repository locally.
```bash 
git clone https://github.com/farattiana/HTML-File-Generator
```
**2. C Compiler:** Install a C Compiler, such as MinGW, to compile and execute the C files present in this project

## Usage
Follow these steps after cloning the repository:

**1. Compilation:** Use C Compiler to generate the executable
 ```bash
gcc main.c -o create-html-repository
 ```

**2. Execution:** Once compiled, run the program using the command: 
```bash
./create-html-repository
```

**3. Environment Variable Configuration:** To execute `create-html-repository` from anywhere, move the executable to a directory included in your PATH environment variable. 

For example, on linux, use the command:
```bash
mv create-html-repository /usr/local/bin/
```

After configuring the executable, you can simply type `create-html-repository` from any directory to launch the program.

