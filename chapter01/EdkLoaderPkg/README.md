# edk2 설치
```bash
git clone --depth=1 https://github.com/tianocore/edk2.git
cd edk2
git submodule update --init
make -C BaseTools
```

# edk2 에서 EdkLoaderPkg 를 링크
```bash
ln -s /Path/To/EdkLoaderPkg
```

# 설정
```bash
. edksetup.sh

vim Config/target.txt
ACTIVE_PLATFORM       = EdkLoaderPkg/EdkLoaderPkg.dsc
TARGET                = DEBUG
TARGET_ARCH           = X64
TOOL_CHAIN_CONF       = Conf/tools_def.txt
TOOL_CHAIN_TAG        = CLANGDWARF
MAX_CONCURRENT_THREAD_NUMBER = 0
BUILD_RULE_CONF = Conf/build_rule.txt
```

# build
```bash
build
```