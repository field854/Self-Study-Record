# the differences of using, typedf and define
## using 
  - using namespace ;eg :using namespace std; using namespace std::string;
  - nickname using xxxxx = yyyyy; eg:
  - template aliasing eg:using namespace std::chrono_literals;

##  typedf
  -  type nickname
  -   compiling
  
## define
  - global introduction
   -  give an alias to the operation with parameters
    - note that it is different from the function definition  
   - confitionals
   - gurads 
  
  
1. 引用 (&)：变量的“分身”
起名对象：具体的变量/对象（内存中真实存在的实体）。

本质：它是变量的一个别名。在底层，它通常被封装成一个“不可改变方向的指针”。

生效时间：运行期间 (Runtime)。程序跑起来后，引用才真正和某个变量绑定。

类型检查：严格。你不能把一个 double 变量的引用给一个 int&。

内存分配：底层会分配空间（通常占用一个指针大小的空间，用来存放目标变量的地址）。

作用域：遵循正常的变量作用域（比如在大括号 {} 结束后失效）。

例子：int a = 10; int &ref = a;

2. using / typedef：类型的“外号”
起名对象：数据类型（类似于给生产零件的“模具”改个名）。

本质：它是类型的别名。它不产生新类型，只是让长类型名变短。

生效时间：编译期间 (Compile time)。编译器在扫描代码时就理解了这个名字。

类型检查：严格。它是类型安全的，编译器能识别别名背后的真实类型。

内存分配：不占内存。它只记录在编译器的符号表里。

作用域：遵循命名空间或类/函数的作用域。

例子：using Vec = std::vector<int>; 或 typedef unsigned long ulong;

3. #define：文字的“复印机”
起名对象：纯文本/字符串（没有任何逻辑的文字替换）。

本质：宏替换。它就像是 Word 里的“全部替换”功能。

生效时间：预处理阶段 (Pre-process)。这是在真正的编译开始之前，由预处理器完成的。

类型检查：完全没有。它只管把 A 换成 B，换完之后如果代码逻辑错了，那是编译器报错的事。

内存分配：不占内存。替换后的值会直接嵌入到代码中。

作用域：全局生效。一旦定义，除非遇到 #undef，否则在整个文件甚至包含它的文件中都有效。

例子：#define PI 3.14