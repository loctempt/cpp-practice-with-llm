def main():
    STYLE_NUM = 4
    FEAT_DIM = 5
    
    styles = [
        [0.90, 0.10, 0.20, 0.10, 0.12],
        [0.10, 0.90, 0.15, 0.10, 0.05],
        [0.04, 0.15, 0.09, 0.92, 0.10],
        [0.10, 0.05, 0.15, 0.30, 0.95]
    ]
    style_names = ["记叙文", "议论文", "散文", "诗歌"]
    
    # 打开指定文件
    with open("task2_matrix_mul.input", "r") as f:
        for line in f:
            line = line.strip()
            if not line:
                continue
            
            # 解析每行5个浮点数
            parts = line.split()
            if len(parts) != FEAT_DIM:
                continue  # 跳过格式错误的行
                
            article = [float(x) for x in parts]
            
            # 矩阵乘法: 4种文体 × 5维特征
            scores = []
            for i in range(STYLE_NUM):
                score = sum(styles[i][j] * article[j] for j in range(FEAT_DIM))
                scores.append(score)
            
            # 输出
            output = " ".join(f"{style_names[i]}: {scores[i]:.2f}" 
                             for i in range(STYLE_NUM))
            print(output)

if __name__ == "__main__":
    main()