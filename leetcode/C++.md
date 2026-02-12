## 字符串

### 获取字符串长度

```c++
#include <iostream>
#include <string>

int main() {
    std::string s = "Hello!";
    
    // 方法 A：使用 .size() (最通用，符合 STL 容器习惯)
    std::cout << s.size() << std::endl; 
    
    // 方法 B：使用 .length() (语义上更符合“字符串长度”)
    std::cout << s.length() << std::endl; 

    return 0;
}
```

### 在末尾添加或删除字符

1. `push_back`
2. `pop_back`