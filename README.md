# “问题求解——基于LLM机制的文章评价”命题

本仓库用于命制”问题求解——基于LLM机制的文章评价”实训题目。

设计文档见 [LLM情境下的实训题目设计](./LLM情境下的实训题目设计（强\)\(1\).md)

## 目录结构

```text
cpp_practice_with_llm/
├── LLM情境下的实训题目设计（强)(1).md     # 题目设计文档
├── README.md                              # 说明文件
├── task1_vector_mul.cpp                   # 任务1：向量点积计算相似度
├── task1_vector_mul.input                 # 任务1输入数据
├── task1_vector_mul.output                # 任务1输出样例
├── task2_matrix_mul.cpp                   # 任务2：矩阵乘法计算文体分类
├── task2_matrix_mul.input                 # 任务2输入数据
├── task2_matrix_mul.output                # 任务2输出样例
├── task3_softmax.cpp                      # 任务3：Softmax归一化
├── task3_softmax.input                    # 任务3输入数据
├── task3_softmax.output                   # 任务3输出样例
├── task4_attention.cpp                    # 任务4：Attention机制组装
├── task4_attention.input                  # 任务4输入数据
├── task4_attention.output                 # 任务4输出样例
└── utils/                                 # 工具目录
    ├── data_gen.cpp                       # 数据生成器
    └── task2_verifier.py                  # 任务2验证脚本
```

## 任务说明

### 任务1：向量点积 (task1_vector_mul.cpp)

实现向量点积计算，用于计算用户输入向量与标准模板向量的相似度。

### 任务2：矩阵乘法 (task2_matrix_mul.cpp)

实现矩阵与向量的乘法，用于根据文章特征向量计算其在不同文体（记叙文、议论文、散文、诗歌）上的得分。

### 任务3：Softmax归一化 (task3_softmax.cpp)

实现带数值稳定性的Softmax函数，将第二题得到的原始分数转化为概率分布。包含三个步骤：平移（减最大值防止溢出）、取指数、归一化。

### 任务4：Attention机制组装 (task4_attention.cpp)

综合多位虚拟阅卷专家的意见进行智能评分。计算流程：文章与专家专长求相似度（Q·K^T）→ Softmax生成决策权重 → 加权融合专家评分（w·V^T）。

## 编译与运行

```bash
# 编译
g++ task1_vector_mul.cpp -o task1_vector_mul
g++ task2_matrix_mul.cpp -o task2_matrix_mul
g++ task3_softmax.cpp -o task3_softmax
g++ task4_attention.cpp -o task4_attention

# 运行（使用输入文件）
./task1_vector_mul < task1_vector_mul.input
./task2_matrix_mul < task2_matrix_mul.input
./task3_softmax < task3_softmax.input
./task4_attention < task4_attention.input
```

## 进度

- [x] 任务1：向量点积
- [x] 任务2：矩阵乘法
- [x] 任务3：Softmax归一化
- [x] 任务4：Attention机制组装
