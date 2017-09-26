```
#include<stdio.h>

int main() {
    int i = 1234567890;
    float f = i;

    printf("i = %d\n", i);
    printf("f = %f\n", f);

    return 0;
}
```

在从int转换为float的过程中，当int的数目比较大的时候，由于float的精度有限，导致个位数或者十位数的精度丢失
程序的结果如下：
``` 
➜  github ./a.out 
i = 1234567890
f = 1234567936.000000
```

note:   如果代码中计算 i - f 应该为多少？ 答案是 0， 因为i - f表达式的时候 i会隐式的转换为float类型
 
