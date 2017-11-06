
void mat_vec(int size, double (*in1)[size], double *in2, double *out);

void mat_mlt(int size, double (*in1)[size], double (*in2)[size], double (*out)[size]);
	
void get_A(int size, double (*mat)[size]);

void printMlt(int size, double (*mat)[size]);

void printVec(int size, double *vec);

void cp(int size, double *in, double *out);

void InitVec(int size, double *out);
