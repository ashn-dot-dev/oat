#!/usr/bin/env python3
import argparse
import json
import re

RE_STRUCT_DECLARATION = re.compile(r"^struct (\w+);$")
RE_FUNCTION_DECLARATION = re.compile(r"^(.+) (\w+)\((.+)\);$")

RE_ARGUMENT = re.compile(r"(.+) (\w+)")

RE_TYPE_STRUCT = re.compile(r"^struct (\w+)$")
RE_TYPE_POINTER = re.compile(r"^(.+)\*$")
RE_TYPE_POINTER_CONST = re.compile(r"^(.+) const\*$")
RE_TYPE_POINTER_TO_VOID = re.compile(r"^void\*$")
RE_TYPE_POINTER_TO_VOID_CONST = re.compile(r"^void const\*$")

def generate_type(s):
    if match := RE_TYPE_STRUCT.match(s):
        return match[1]
    if match := RE_TYPE_POINTER_TO_VOID_CONST.match(s):
        return f"*any"
    if match := RE_TYPE_POINTER_TO_VOID.match(s):
        return f"*any"
    if match := RE_TYPE_POINTER_CONST.match(s):
        return f"*{generate_type(match[1])}"
    if match := RE_TYPE_POINTER.match(s):
        return f"*{generate_type(match[1])}"
    if s == "int":
        return "sint"
    return s

def generate_struct_declaration(line):
    name = RE_STRUCT_DECLARATION.match(line)[1]
    return f"struct {name} {{ var opaque: any; }}"

def generate_function_declaration(line):
    def generate_function_argument(s):
        match = RE_ARGUMENT.match(s)
        type = generate_type(match[1])
        name = match[2]
        return f"{name}: {type}"

    match = RE_FUNCTION_DECLARATION.match(line)
    type = generate_type(match[1])
    name = match[2]
    args = "" if match[3] == "void" else ", ".join([generate_function_argument(s) for s in match[3].split(", ")])
    return f"extern func {name}({args}) {type};"

def main(args):
    with open(args.header) as f:
        lines = [s.strip() for s in f.readlines()]
    print("import \"c\";")
    print("\n", end="")
    print("\n".join([generate_struct_declaration(s) for s in lines if RE_STRUCT_DECLARATION.match(s)]))
    print("\n", end="")
    print("\n".join([generate_function_declaration(s) for s in lines if RE_FUNCTION_DECLARATION.match(s)]))

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Generate OAT bindings")
    parser.add_argument("header")
    main(parser.parse_args())
