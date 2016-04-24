
package semaphoresimpl;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

/**
 *
 * @author Chand
 */
/**
 * Three processes are involved in printing a file. Process A reads the file
 * data from the disk to Buffer 1, Process B copies the data from Buffer 1 to
 * Buffer 2, finally Process C takes the data from Buffer 2 and print it. Assume
 * all three processes operate on one (file) record at a time, both buffers'
 * capacity are one record. Write a program to coordinate the three processes
 * using semaphores.
 *
 */

/**
 * This class will show how Semaphores work
 * There are 2 semaphores s1 and s2.
 * s1 operates between the classes MyFileReader and BufferCopier
 * s2 operates between the classes BufferCopier and BufferPrinter
 **/
class SemaphoresDemo {

    private String fileIn;
    private String copyStr;
    private String FileName;
    private BinSemaphore s1;
    private BinSemaphore s2;

    SemaphoresDemo(String str) {
        FileName = str;
        fileIn = null;
        copyStr = null;
        s1 = new BinSemaphore();
        s2 = new BinSemaphore();
    }

    /**
     * Semaphore class definition
     * Methods up and down are similar to V() and P() respectively
     **/
    class BinSemaphore {

        private int x;

        BinSemaphore() {
            x = 1;
        }

        //similar to V()
        public void up() {
            x++;
            synchronized (this) {
                notify();
            }
        }

        //Similar to V()
        public void down() {
            try {
                
                synchronized (this) {
                    while (x <= 0) {
                        wait();
                    }
                }
            } catch (InterruptedException ex) {
                System.out.println("Wait stopped...");
            }
            x--;
        }

    }

    /**
     * This method is called by the main method to execute the operations
     * In this method, 3 objects are created each running on their own threads
     * and then executes read, copy and print functions to do them appropriately.
     */
    
    void printFileContents() {
        MyFileReader p1 = new MyFileReader(FileName);
        BufferCopier p2 = new BufferCopier();
        BufferPrinter p3 = new BufferPrinter();

        p2.start();
        p3.start();

    }

    /**
     * THis class reads the file and stores the contents to fileIn
     * String.
     **/
    
    public class MyFileReader implements Runnable {

        private BufferedReader br;
        private Thread t;
        private FileReader fr;
        File file;

        MyFileReader(String FileNam) {
            t = new Thread(this, "FileReader Thread");
            file = new File(FileNam);
            try {
                fr = new FileReader(file);
                br = new BufferedReader(fr);
            } catch (FileNotFoundException ex) {
                System.out.println("Unable to load file...");
            }
            System.out.println("FileReader starting...");
            t.start();

        }

        @Override
        public void run() {

            try {

                s1.down();
                fileIn = br.readLine();
                s1.up();
                while (fileIn != null) {
                    //Semaphore Implementation
                    s1.down();
                    fileIn = br.readLine();
                    s1.up();
                    Thread.yield();
                }
                fr.close();
            } catch (IOException ex) {
                System.out.println("Unable to read from file...");
            }

        }

    }

    /**
     * THis class copies the contents in fileIn and paste them in copyStr String
     **/
    public class BufferCopier implements Runnable {

        private Thread t;

        BufferCopier() {
            t = new Thread(this, "BufferCopierThread");
        }

        public void start() {
            System.out.println("BufferCopier is starting...");
            t.start();

        }

        @Override
        public void run() {
            while (fileIn != null) {
                //Semaphore Implementation
                s1.down();
                s2.down();
                copyStr = fileIn;
                s1.up();
                s2.up();
                Thread.yield();
            }
            copyStr = null;
        }

    }

    /**
     * THis class prints the contents of  copyStr String to console.
     **/
    public class BufferPrinter implements Runnable {

        private Thread t;

        BufferPrinter() {
            t = new Thread(this, "BufferPrinterThread");
        }

        public void start() {
            System.out.println("BufferPrinter is starting...");
            t.start();
        }

        @Override
        public void run() {
            
            while (copyStr != null) {
                //Semaphore Implementation
                s2.down();
                System.out.println(copyStr);
                s2.up();
                Thread.yield();
            }
        }

    }
}

/**
* THis is the main class.
**/
public class SemaphoresImpl {

    
    public static void main(String[] args) {
        // TODO code application logic here
        SemaphoresDemo s = new SemaphoresDemo("C:\\TEMP\\Source.txt");
        s.printFileContents();

    }

}
