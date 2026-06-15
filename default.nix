{ stdenv, clang, cmake, make, nasm }:
stdenv.mkDerivation {
  pname = "foolisbox";
  version = "1.0";

  src = ./.;

  hardeningDisable = [ "stackprotector" ];

  buildPhase = ''
    cmake .
    make
  '';

  installPhase = ''
    mkdir -p $out/bin
    cp foolisbox $out/bin/foolisbox
    
    ln -s foolisbox $out/bin/cat
    ln -s foolisbox $out/bin/echo
  '';
}
