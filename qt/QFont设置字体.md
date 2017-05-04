
## 设置字体
```
// set palette color.
QPalette palette_font;
palette_font.setColor(QPalette::WindowText, Qt::red);

// set font.
QFont font;
font.setPointSize(55);
font.setBold(true);

// label.
QLabel *label=new QLabel("设置字体",this);
label->setFont(font);
label->setPalette(palette_font);

```
