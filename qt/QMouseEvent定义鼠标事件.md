
以拖动MainWindow窗口为例，

（1）声明

```

#include <QMouseEvent>

//......
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    QPoint window_pos;
    QPoint mouse_pos;
    bool is_mouse_press;

```

（2）定义

```
//......
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        window_pos=this->pos();
        mouse_pos=event->globalPos();
        is_mouse_press=true;
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        is_mouse_press=false;
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(is_mouse_press==true){
        move(window_pos+(event->globalPos()-mouse_pos));
    }
}
```
