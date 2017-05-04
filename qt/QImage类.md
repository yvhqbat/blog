
## QImage类
### Detailed Description
> The QImage class provides a hardware-independent image representation that allows direct access to the pixel data, and can be used as a paint device.

> Qt provides four classes for handling image data: QImage, QPixmap, QBitmap and QPicture.
> QImage is designed and optimized for I/O, and for direct pixel access and manipulation.
> while QPixmap is designed and optimized for showing images on screen.
> QBitmap is only a convenience class that inherits QPixmap, ensuring a depth of 1.
> Finally, the QPicture class is a paint device that records and replays QPainter commands.


> Because QImage is a QPaintDevice subclass, QPainter can be used to draw directly onto images. When using QPainter on a QImage, the painting can be performed in another thread than the current GUI thread.

> The QImage class supports several image formats described by the Format enum. These include monochrome, 8-bit, 32-bit and alpha-blended images which are available in all versions of Qt 4.x.

> QImage provides a collection of functions that can be used to obtain a variety of information about the image.
> There are also several functions that enables transformation of the image.
> QImage objects can be passed around by value since the QImage class uses implicit data sharing.
> QImage objects can also be streamed and compared.


QImage类提供了一个硬件无关的图像表示方法，该图像可以逐像素被访问和用于画图设备。

Qt提供了QImage、QPixmap、QBitmap和QPicture四种图像操作类。
(1) QImage类主要用于I/O和直接逐像素访问、操作；
(2) QPixmap主要用于在屏幕中显示图像；
(3) QBitmap是一个基于方便考虑继承自QPixmap的提供1bit深度二值图像的类；
(4) QPicture是一个可以记录和响应QPainter类命令的画图设备。

QImage继承自QPaintDevice，QPainter类可以被用来直接在图像上进行画操作。

QImage类支持QImage::Format枚举变量描述的多种图像类型，包括8-bit, 32-bit 和 alpha-blended images

QImage提供很多可以用于获取图像信息和进行图像变换的函数。

#### 1. 读写图像

QImage有多种读取图像的方法。图像文件可以在生成QImage对象的过程中或者在之后用load和loadFromData方法读取，也可以用静态方法fromData利用给定的数据构造。读取的图像可以是存储在磁盘中或某个嵌入式应用程序的资源。

save方法可以用来保存QImage对象。

#### 2. 图像信息

QImage类提供了很多用于获取图像信息的方法。

如size、width、height、dotsPerMeterX、dotsPerMeterY、pixel、text、depth

#### 3. 像素赋值操作

1).32-bit图像

用qRgb或qRgba方法设置一个颜色值，再用sexPixel将相应像素设置为相应颜色

2).8-bit和1-bit二值图像

每一个像素的值是color table List中的一个索引，因此像素的值只能被改成一个在color table List中已经定义的值。如果想往color table List中加入新的值，可以用setColor方法。

#### 4. 图像格式

QImage中的每一个像素由一个整数表示，这个整数的大小取决于不同的图像格式。

8-bit图像的每一个像素的值是color table List中的一个索引，32-bit每一个像素拥有一个自己的rgb值(RGB、ARGB、premultiplied ARGB)

图像的格式可以用format方法得到，convertToFormat方法可以用来将一种格式的图像转换为另外一种，allGray和isGrayscale方法可以用来检查一个彩色图像是否可以被安全转换为灰度图像。

#### 5. 图像变换

mirrored、scaled、rgbSwapped、scaledToWidth、scaledToHeight、transformed...

### QImage绘图
主要就是重写窗口平台的虚函数：void paintEvent(QPaintEvent *event);
```
void paintEvent(QPaintEvent *event)
{
QImage image;
image.load("test.jpg");  //用QImage导入图片

QPainter draw(this);  //创建QPainter，将指针传入该设备

QRect rect(0,0,this->width(),this->height());  //创建绘图区域

draw.drawImage(rect,image);  //绘图，drawImage有很多重载函数，可根据自己的需要调用相应函数
}
```
