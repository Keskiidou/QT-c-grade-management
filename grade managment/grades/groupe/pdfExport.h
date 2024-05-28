#ifndef PDFEXPORT_H
#define PDFEXPORT_H
#include <QTableView>

class pdfExport
{
public:
    pdfExport();

    void exportTableToPDF(const QTableView* tableView);
};
#endif // PDFEXPORT_H
