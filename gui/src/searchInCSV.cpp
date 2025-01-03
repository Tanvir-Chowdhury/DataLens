#include "searchInCSV.h"
#include <QApplication>
#include <QHeaderView>
#include <QInputDialog>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QVBoxLayout>
#include <QWidget>

void searchInCSV(const QString &csvFileName, const std::string &dataFolder) {
  // Create a Database object and load the CSV file
  Database db;
  db.loadDatabase(dataFolder);

  // Get the LinkedList for the specified CSV file
  LinkedList *table = db.getTable(csvFileName.toStdString());
  if (!table) {
    QMessageBox::critical(nullptr, "Error",
                          "Table not found for file: " + csvFileName);
    return;
  }

  // Display a search dialog
  bool ok;
  QString searchKey = QInputDialog::getText(
      nullptr, "Search in " + csvFileName,
      "Enter code to search:", QLineEdit::Normal, QString(), &ok);

  if (ok && !searchKey.isEmpty()) {
    int columnIndex = 0; // Default to the first column
    Node *result = db.search(csvFileName.toStdString(), searchKey.toStdString(),
                             columnIndex);

    if (result) {
      // Display the found data
      QWidget resultWindow;
      resultWindow.setWindowTitle("Search Result");

      QVBoxLayout *layout = new QVBoxLayout(&resultWindow);

      QLabel *resultLabel = new QLabel("Search Result Found:");
      layout->addWidget(resultLabel);

      QTableWidget *tableWidget = new QTableWidget(&resultWindow);
      tableWidget->setColumnCount(table->columns.size());
      QStringList headers;
      for (const auto &column : table->columns) {
        headers << QString::fromStdString(column);
      }
      tableWidget->setHorizontalHeaderLabels(headers);

      // Set header to resize to contents for full visibility
      tableWidget->horizontalHeader()->setSectionResizeMode(
          QHeaderView::ResizeToContents);
      tableWidget->verticalHeader()->setVisible(false);

      int row = 0;
      tableWidget->insertRow(row);
      for (size_t col = 0; col < result->data.size(); ++col) {
        tableWidget->setItem(
            row, static_cast<int>(col),
            new QTableWidgetItem(QString::fromStdString(result->data[col])));
      }

      layout->addWidget(tableWidget);

      QPushButton *closeButton = new QPushButton("Close", &resultWindow);
      layout->addWidget(closeButton);

      QObject::connect(closeButton, &QPushButton::clicked, &resultWindow,
                       &QWidget::close);

      resultWindow.resize(800, 400); // Adjust size for better visibility
      resultWindow.show();

      QApplication::exec(); // Show search result and run the app loop
    } else {
      QMessageBox::warning(nullptr, "Not Found",
                           "Code not found in the table.");
    }
  } else {
    QMessageBox::information(nullptr, "Search Canceled",
                             "Search canceled or empty input.");
  }
}
