class payload
{
        public:
                int* k;
                int count;

                payload();
                payload(char fn[]);
                payload(int s);
                ~payload();
                void readFile(char fn[]);
                void readFile2(char fn[]);
                void print();
                bool checksorted(bool verbose);
};

