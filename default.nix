{ stdenv, clang, cmake, gnumake, nasm }:
stdenv.mkDerivation {
  pname = "foolisbox";
  version = "1.0";

  src = ./.;

  hardeningDisable = [ "stackprotector" ];

  nativeBuildInputs = [ 
      cmake 
      nasm
      gnumake
      clang
    ];

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
