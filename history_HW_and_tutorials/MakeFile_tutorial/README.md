# Makefile tutorial

## 標準的 make 語法

    <target>: [dependency]
        <command>

**Note:**
1. command 前面的空白需要是一個 **Tab**
2. target 需要是一個會真實存在/產生的**檔案**，除非他是 [fake目標](#fake-目標)
3. 當 dependency 的檔案不存在時，make 將會試著利用其他的 **target** 來產生此相依檔案，如果找不到則**編譯失敗**
4. **all**這個 target 是一個 make 預設的fake目標，當你直接在 terminal 執行 `make` 時，如果有 all 便會優先執行它，沒有則找第一個 target。
5. make會與上次編譯比較，當 **dependency** 或 **target** 中的檔案有被變更過時，便重新執行 **command**，反之則不會重新執行，沿用上次的執行結果

[Example 1](/makefile1/makefile)    
[Example 2](/makefile2/makefile) 

## Fake 目標
當 **target** 不是真實存在的**檔案**時，此目標即為 **Fake 目標** ，須在 **.PHONY** 中被定義

    .PHONY: dirs clean run
    
    ...
    
    dirs:
        mkdir -p $(BIN)

    clean: $(BIN)
        rm -rf $^

    run:
        ./bin/ut_all

dirs/clean/run皆不是真正存在的檔案，因此需加入**.PHONY**中

[Example 3](/makefile3/makefile)

## 常見的makefile變數定義

    CC = g++
    // C Compiler

    LIB = -lgtest -lpthread
    // Libraries

    CFLAGS = -I.
    // Compiler Flags

- 當然，你也可以自己定義你喜歡的變數

[Example 4](/makefile4/makefile)    
[Example 5](/makefile5/makefile)

## 常用的自動化變數

    $@：目前的目標項目名稱。
    $<：代表目前的相依性項目。
    $*：代表目前的相依性項目，但不含副檔名。
    $?：代表需要重建（被修改）的相依性項目。

[Example 6](/makefile6/makefile)