
## QFileDialog
> 全部来自于Qt文档。
### Detailed Description
> The QFileDialog class provides a dialog that allow users to select files or directories.
The QFileDialog class enables a user to traverse the file system in order to select one or many files or a directory.

### getOpenFileName
The easiest way to create a QFileDialog is to use the static functions.
```
QString fileName = QFileDialog::getOpenFileName(
                        this,
                        tr("Open Image"),
                        "/home/jana",
                        tr("Image Files (*.png *.jpg *.bmp)"));
```

In the above example, a modal QFileDialog is created using a static function.
The dialog initially displays the contents of the` "/home/jana" `directory,
and displays files matching the patterns given in the string `"Image Files (*.png *.jpg *.bmp)"`.
The parent of the file dialog is set to this, and the window title is set to `"Open Image"`.

### getOpenFileNames
```
QStringList files = QFileDialog::getOpenFileNames(
                         this,
                         "Select one or more files to open",
                         "/home",
                         "Images (*.png *.xpm *.jpg)");
```
