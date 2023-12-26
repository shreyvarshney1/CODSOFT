#include <QApplication>
#include <QWidget>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <opencv2/opencv.hpp>

class ImageProcessingTool : public QWidget {
    Q_OBJECT

public:
    ImageProcessingTool(QWidget *parent = nullptr) : QWidget(parent) {
        QVBoxLayout *layout = new QVBoxLayout;

        QLabel *imageLabel = new QLabel;
        layout->addWidget(imageLabel);

        QPushButton *loadButton = new QPushButton("Load Image");
        layout->addWidget(loadButton);
        connect(loadButton, &QPushButton::clicked, this, &ImageProcessingTool::loadImage);

        QPushButton *grayscaleButton = new QPushButton("Grayscale");
        layout->addWidget(grayscaleButton);
        connect(grayscaleButton, &QPushButton::clicked, this, &ImageProcessingTool::applyGrayscale);

        QPushButton *blurButton = new QPushButton("Blur");
        layout->addWidget(blurButton);
        connect(blurButton, &QPushButton::clicked, this, &ImageProcessingTool::applyBlur);

        QPushButton *sharpenButton = new QPushButton("Sharpen");
        layout->addWidget(sharpenButton);
        connect(sharpenButton, &QPushButton::clicked, this, &ImageProcessingTool::applySharpen);

        QPushButton *saveButton = new QPushButton("Save Image");
        layout->addWidget(saveButton);
        connect(saveButton, &QPushButton::clicked, this, &ImageProcessingTool::saveImage);

        setLayout(layout);
    }

private slots:
    void loadImage() {
        QString filePath = QFileDialog::getOpenFileName(this, "Open Image File", "", "Images (*.png *.jpg *.bmp)");
        if (!filePath.isEmpty()) {
            image = cv::imread(filePath.toStdString());
            displayImage();
        }
    }

    void displayImage() {
        cv::cvtColor(image, image, cv::COLOR_BGR2RGB);  // OpenCV loads images in BGR, convert to RGB
        QImage img(image.data, image.cols, image.rows, image.step, QImage::Format_RGB888);
        QLabel *imageLabel = findChild<QLabel *>();
        imageLabel->setPixmap(QPixmap::fromImage(img));
    }

    void applyGrayscale() {
        cv::cvtColor(image, image, cv::COLOR_BGR2GRAY);
        displayImage();
    }

    void applyBlur() {
        cv::GaussianBlur(image, image, cv::Size(5, 5), 0);
        displayImage();
    }

    void applySharpen() {
        cv::Mat kernel = (cv::Mat_<float>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
        cv::filter2D(image, image, image.depth(), kernel);
        displayImage();
    }

    void saveImage() {
        QString filePath = QFileDialog::getSaveFileName(this, "Save Image", "", "Images (*.png *.jpg *.bmp)");
        if (!filePath.isEmpty()) {
            cv::imwrite(filePath.toStdString(), image);
        }
    }

private:
    cv::Mat image;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    ImageProcessingTool tool;
    tool.setWindowTitle("Image Processing Tool");
    tool.show();
    return app.exec();
}

#include "main.moc"
