# osxcross-target
Build CGO enabled darwin (mac) binaries from linux using [GoReleaser Action](https://github.com/goreleaser/goreleaser-action).
<hr>

Your `.github/workflows/release.yml` should include this:
```yml
-
  name: OSXCross for CGO Support
  run: |
    mkdir ../../osxcross
    git clone https://github.com/plentico/osxcross-target.git ../../osxcross/target
```

<details>
<summary>Note on libcrypto (OpenSSL)</summary>
<br>
  
We updated this project for Ubuntu 20.04, but OSXCross still needs an older version of OpenSSL so you might need to add a step that looks like this:
```yml
-
  name: Downgrade libssl
  run: |
    echo 'deb http://security.ubuntu.com/ubuntu bionic-security main' | sudo tee -a /etc/apt/sources.list
    sudo apt update && apt-cache policy libssl1.0-dev
    sudo apt-get install libssl1.0-dev
```

See more details here: https://github.com/plentico/osxcross-target/issues/1

</details>

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
