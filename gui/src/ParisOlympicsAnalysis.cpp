#include "ParisOlympicsAnalysis.h"

ParisOlympicsAnalysis::ParisOlympicsAnalysis(QWidget *parent)
    : QWidget(parent), currentImageIndex(0) {
  QVBoxLayout *layout = new QVBoxLayout(this);

  imageLabel = new QLabel(this);
  headingLabel = new QLabel(this); // Initialize the heading label
  imageLabel->setAlignment(Qt::AlignCenter);
  layout->addWidget(imageLabel);

  headingLabel->setAlignment(Qt::AlignCenter); // Align heading label
  layout->addWidget(headingLabel);             // Add to layout

  QPushButton *nextButton = new QPushButton("Next Image", this);
  connect(nextButton, &QPushButton::clicked, this,
          &ParisOlympicsAnalysis::showNextImage);
  layout->addWidget(nextButton);

  setLayout(layout);
  setWindowTitle("Paris Olympics Analysis");
  resize(800, 600);

  // Set the specific folder path directly in the code
  imageFolder = "/home/sujat/core/images/"; // Set your desired folder path here
  loadImagesFromFolder();
}

void ParisOlympicsAnalysis::resizeEvent(QResizeEvent *event) {
  QWidget::resizeEvent(event);
  if (!currentImage.isNull()) {
    // Scale the current image to fit the resized window
    imageLabel->setPixmap(currentImage.scaled(
        imageLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
  }
}

void ParisOlympicsAnalysis::showNextImage() {
  if (!images.isEmpty()) {
    currentImageIndex = (currentImageIndex + 1) % images.size();
    showImage(currentImageIndex);
  }
}

void ParisOlympicsAnalysis::loadImagesFromFolder() {
  QDir dir(imageFolder);
  QStringList filters;
  filters << "*.png"
          << "*.jpg"
          << "*.jpeg"
          << "*.bmp"
          << "*.gif";
  images = dir.entryList(filters, QDir::Files);

  currentImageIndex = 0;
  if (!images.isEmpty()) {
    showImage(currentImageIndex);
  }
}

void ParisOlympicsAnalysis::showImage(int index) {
  if (index < 0 || index >= images.size()) {
    imageLabel->setText("No image available.");
    if (headingLabel)
      headingLabel->clear(); // Clear the heading if out of bounds
    return;
  }

  QString imagePath = QDir(imageFolder).filePath(images[index]);
  QPixmap pixmap(imagePath);

  if (pixmap.isNull()) {
    imageLabel->setText("Failed to load image: " + images[index]);
    if (headingLabel)
      headingLabel->clear(); // Clear heading if image fails to load
  } else {
    currentImage = pixmap; // Store the current image
    imageLabel->setPixmap(currentImage.scaled(
        imageLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    // Only set heading if it's initialized
    if (headingLabel) {
      headingLabel->setText(images[index].section(
          '.', 0, 0)); // Show image name without extension
    }
  }
}

