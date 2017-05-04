
## QSystemTrayIcon

```
//system tray.
QSystemTrayIcon *tray;
tray=new QSystemTrayIcon();
tray->setIcon(QIcon(":/image/lena.jpg"));
tray->setToolTip("a trayicon example");
tray->show();
tray->showMessage("title","content");
```
