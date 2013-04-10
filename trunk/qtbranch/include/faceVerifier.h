#ifndef _INCL_FACE_VERIFYER
#define _INCL_FACE_VERIFYER

#include "ui_faceVerifier.h"
#include "opencvWebcam.h"
#include "detector.h"
#include "verifier.h"

/**
* Face Verifyer class. The main window used to train the face.
*/
class faceVerifyer: public QMainWindow
{
    Q_OBJECT

    private:
        int timerId;
        int imageReturned;
        int faceFound;
        int faceVerified;
        bool imageSave;
        static const int FACE_COUNT = 13;

        /**
         * UI object of the face trainer main window
         */
        Ui::faceVerifyer ui;

    private slots:
        /**
         * Slot - Shows the first tab (Instructions tab)
         */
        void showTab1();

        /**
         * Slot - Shows the second tab (Verify tab)
         */
        void showTab2();

        /**
         * Slot - Shows the last tab (Thank you tab)
         */
        void showTab3();

        /**
         * Slot - Capture Failures
         */
        void captureClick();

        /**
         * Slot - Shows the about dialog
         */
        void about();

        /**
         * Slot - Removes the selected set from QList, 
         * and removes the files on disk as well
         */
        void removeSelected();


    protected:
        /**
         * timerEvent of MainWindow overload
         */
        void timerEvent(QTimerEvent*);      
        /**
         * Save an image
         */
         void saveImage( cv::Mat image);

    public:
        /**
         * The constructor
         * Sets up the UI for the main window and connect signals to slots
         */
        faceVerifyer(QWidget* parent = 0);

        /**
         * The destructor
         */
        virtual ~faceVerifyer();

        /**
         * OpenCV webcam object
         */
        opencvWebcam webcam;

        /**
         * Detector object
         */
        detector newDetector;

        /**
         * Verifier object
         */
        verifier newVerifier;

        /**
         * Populates the QList with Face Image Sets in $HOME/.pam-face-authentication/faces/
         */
        void populateQList();

        /**
         * Crappy function i use to test against a set of Images, ignore it
         */
        void verify();

        /**
         * Translating messages from detector class
         * @param int for Message index
         */
        QString getQString(int messageIndex);

        public slots:
            /**
             * Sets the image of QGraphicsView which displays the Webcam
             * @param input that needs to be set.
             */
            void setQImageWebcam(QImage*);

        /**
         * Sets the information bar with message of the current state
         * @param message The Message that needs to be set.
         */
        void setIbarText(QString message);

        bool notify( QObject *object, QEvent *event);
};

#endif // _INCL_FACE_VERIFYER
