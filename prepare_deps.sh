#!/bin/bash
set -eu

: ${TMP_DIR:=tmp-deps}
: ${INSTALL_DIR:=${TMP_DIR}/install}
: ${VERSION:=6.1.2}
: ${MAKE_OPTS:=-j4}

mkdir -p "$TMP_DIR" "$INSTALL_DIR"

abs_install_dir="$(cd "$INSTALL_DIR"; pwd)"

cd "$TMP_DIR"

gmp_basename="gmp-${VERSION}"
gmp_archive_file="${gmp_basename}.tar.bz2"
if [[ ! -f "$gmp_archive_file" ]]; then
  url="https://gmplib.org/download/gmp/${gmp_archive_file}"
  curl -LO "$url"
fi
if [[ ! -d "$gmp_basename" ]]; then
  tar xvzf "$gmp_archive_file"
fi

cd "$gmp_basename"

./configure --prefix="$abs_install_dir" --enable-cxx
make "$MAKE_OPTS"
make check
make install
