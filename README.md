# osxcross-target
Build CGO enabled darwin (mac) binaries from linux using [GoReleaser Action](https://github.com/goreleaser/goreleaser-action).
<hr>

Your `.github/workflows/release.yml` should include this:
```yml
-
  name: OSXCross for CGO Support
  run: |
    mkdir ../../osxcross
    git clone https://github.com/AndriyKalashnykov/osxcross-target.git ../../osxcross/target
```

Your `.goreleaser.yml` should have separate builds for linux and mac like this:
```yml
builds:
- id: linux-build
  env:
  - CGO_ENABLED=1
  goos:
  - linux
  ignore:
  - goos: linux
    goarch: 386
- id: darwin-build
  ldflags:
  - -s
  env:
  - CGO_ENABLED=1
  - CC=/home/runner/work/osxcross/target/bin/o64-clang
  - CXX=/home/runner/work/osxcross/target/bin/o64-clang++
  goos:
  - darwin
  ignore:
  - goos: darwin
    goarch: 386
```

**Note:** the values for `CC` and `CXX` must be exactly what is referenced above because the paths are hardcoded.
