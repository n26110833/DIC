該repo紀錄NCKU「Digital IC Design（數位積體電路設計）」課程中的作業，
> 每個作業放在獨立的資料夾中，包含 RTL 原始碼、測試檔案與報告。
---

## 📂 目錄結構

```

/
├── HW1\_MaxMinSelector/
│   ├── MMS\_4num.v
│   ├── MMS\_8num.v
│   ├── MMS\_tb.v
│   ├── test\_data\_4num.dat
│   ├── golden\_data\_4num.dat
│   ├── test\_data\_8num.dat
│   ├── golden\_data\_8num.dat
│   └── report.pdf
├── HW2\_Rails/
│   ├── rails.v
│   ├── tb.v
│   ├── test\_data\_rails.dat
│   ├── golden\_data\_rails.dat
│   └── report.pdf
├── HW4\_AtrousConvolution/
│   ├── ATCONV.v
│   ├── testfixture.v
│   ├── img.dat
│   ├── layer0\_golden.dat
│   ├── layer1\_golden.dat
│   ├── main.py         # 軟體驗證程式
│   └── report.pdf
└── README.md

````

---

## 🚀 專案簡介

「Digital IC Design」是一門介紹組合邏輯、時序電路與記憶體介面設計的課程
1. **HW1 – Max-Min Selector**：設計 4-input 及 8-input 的最大/最小值選擇器。  
2. **HW2 – Rails**：模擬 dead-end 火車站，以 stack 判斷給定進出序列是否可行。  
4. **HW4 – Atrous Convolution**：實現兩層 atrous convolution + max-pooling 的影像處理電路，並撰寫軟體驗證程式。

---

## 📖 各作業說明

### HW1 – Max-Min Selector

- **功能**：4-input 與 8-input 的最大/最小值組合電路  
- **RTL 檔案**：`MMS_4num.v`, `MMS_8num.v`  
- **測試檔**：ModelSim testbench (`MMS_tb.v`)、`*.dat`、`golden_data_*.dat`  
- **報告**：`report.pdf`（電路設計原理、時序圖、模擬結果截圖）  

#### 編譯 & 模擬
```bash
# 進到作業資料夾
cd HW1_MaxMinSelector

# 編譯 RTL
vlog MMS_4num.v MMS_8num.v MMS_tb.v

# 連結並執行模擬
vsim -c work.MMS_tb -do "run -all; quit"
````

---

### HW2 – Rails

* **功能**：判斷給定進出站火車序列是否可行
* **RTL 檔案**：`rails.v`
* **測試檔**：`tb.v`、`test_data_rails.dat`、`golden_data_rails.dat`
* **報告**：`report.pdf`

#### 編譯 & 模擬

```bash
cd HW2_Rails
vlog rails.v tb.v
vsim -c work.tb -do "run -all; quit"
```

---

### HW4 – Atrous Convolution

* **功能**：對 64×64 灰階影像做 replicate padding、dilation=2 atrous convolution、ReLU，接著 2×2 max-pooling + round-up。
* **RTL 檔案**：`ATCONV.v`、`testfixture.v`
* **輸入資料**：`img.dat`
* **Golden 資料**：`layer0_golden.dat`, `layer1_golden.dat`
* **軟體驗證**：`main.py`（或 `main.c`/`main.cpp`）
* **報告**：`report.pdf`

#### 軟體驗證

```bash
cd HW4_AtrousConvolution
python3 main.py   # 產生 img.dat, layer0_golden.dat, layer1_golden.dat
```

#### 編譯 & 模擬

```bash
vlog ATCONV.v testfixture.v
vsim -c work.testfixture -do "run -all; quit"
```

---

## 🔧 環境需求

* ModelSim / QuestaSim
* Quartus Prime（針對 HW4 gate-level 模擬與綜合）
* Python 3（僅 HW4 軟體驗證）

---

## 📄 授權條款

本專案採用 MIT License，詳細請見 [LICENSE](LICENSE)。

---

