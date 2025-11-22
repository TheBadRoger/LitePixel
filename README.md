# LitePixel

利用图形学技术等直接生成图像（PPM格式）

再利用[FFmpeg](https://github.com/FFmpeg/FFmpeg)对图像进行拼接，形成一段连续的视频

> 灵感启发自Tsoding的视频：[Тsфdiиg - Graphics API is irrelevant](https://x.com/tsoding/status/1989446257882829223)

## 当前进度

着色器的像素点RGB功能已经初步完成，利用PPM格式可以渲染出图片。

下一步准备实现图形抽象层和光栅化