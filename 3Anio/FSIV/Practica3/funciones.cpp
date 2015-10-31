#include "funciones.hpp"

void help(){

	cout << "Ayuda con los comandos: " << endl;
	cout << "-h: Muestra la ayuda del programa" << endl;
	cout << "-i nombreImagen: Imagen que se va a cargar para el programa" << endl;
	cout << "-m nombreMascara: Mascara a aplicar para la imagen" << endl;
	cout << "-o nombreImagenSalida: Imagen de salida segmentada" << endl;
	cout << "-r [0,1]: Frecuencia de corte del filtro" << endl;
	cout << "n [1,10]: Orden del filtro butterworth paso baja" << endl;
	cout << "g [0.0, 5.0]: Ganancia del realce" << endl;
}

void unsharp(Mat imagenPasoBaja, Mat imagen, Mat &output, float g){
	for(int i=0; i<imagen.rows; i++){
		for(int j=0; j<imagen.cols; j++){
			output.at<uchar>(i,j) = (g+1)*imagen.at<uchar>(i,j) - g*imagenPasoBaja.at<uchar>(i,j);
		}
	}
}

void butterworth(Mat &imagenPasoBaja, float r, int n){

	for(int i=0; i<imagenPasoBaja.rows; i++){
		for(int j=0; j<imagenPasoBaja.cols; j++){
			imagenPasoBaja.at<uchar>(i,j) = imagenPasoBaja.at<uchar>(i,j) * 1/(1+pow((1+r),2*n));
		}
	}
	//Ya tenemos la imagen con paso bajo
}

void butterworthMascara(Mat &imagenPasoBaja, Mat &mascara, float r, int n){

	for(int i=0; i<imagenPasoBaja.rows; i++){
		for(int j=0; j<imagenPasoBaja.cols; j++){
			//Comprobamos la mascara
			if(mascara.at<uchar>(i,j)!=0){
				imagenPasoBaja.at<uchar>(i,j) = 1/(1+pow((1+r),2*n));
			}
		}
	}
}