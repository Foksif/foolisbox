{ pkgs ? import <nixpkgs> {} }:

let
  clangStdenv = pkgs.llvmPackages.stdenv;
in
pkgs.mkShell.override { stdenv = clangStdenv; } {
  nativeBuildInputs = with pkgs; [
    cmake
    nasm
    llvmPackages.clang
    llvmPackages.bintools 
  ];
}
