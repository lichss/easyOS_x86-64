# DO NOT READ ME 


修错日记：


```C
' __asm__(".code16gcc");  /*惨痛教训 这个指令必须放在文件第一行，不然很可能会不生效*/ '
```
在[loader_16.c](./source/loader/loader_16.c) 中第一行习惯性写`#inclde "loader.h"` 导致`__asm__();`没有正常生效，导致后面lgdt函数失效，所以GDT寄存器的值一直不对。