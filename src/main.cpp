#include "main.h"

using namespace std;

int main(int argc, char *argv[])
{
    QTextStream out(stdout);
    QCoreApplication ed(argc, argv);
    ed.setApplicationName("Image Encoder/Decoder");
    ed.setApplicationVersion("1.0");


    /* parser*/
    QCommandLineParser parser;
    setup_parser(parser);
    parser.process(ed);


    /* welcome message */
    welcome_msg(parser,out);


    /* options switch */
    switch (parser.optionNames().isEmpty()) {
    case 1:
        break;
    case 0:
        if (parser.optionNames()[0] == QString("e")) {
            QString path = parser.value("e");
            out << "Encoding started..." << endl << endl;
            out << "Path to file is:" << " " << path << endl << endl;
            edImageReader imgreader(path);
            imgreader.image_info(out);
            imgreader.pixel_data(out);
            out << endl;
            encoder(out, path);
            out << endl;
        } else if (parser.optionNames()[0] == QString("d")) {
            QString path = parser.value("d");
            out << "Decoding started..." << endl;
            out << "Path to file is:" << " " << path << endl << endl;
            decoder(out, path);
            out << endl;
        } else if (parser.optionNames()[0] == QString("h")) {
            /* just nothing happens, as help text is in welcome message*/
        } else break;
    }


    return 0;
}

