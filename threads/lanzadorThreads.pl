#!/usr/bin/perl

# Fichero para automatización de ejecución por lotes de un ejecutable
# dado parámetros de entrada.
# $ --> variable
# @ --> vector
$repeticiones = 30; #30 repeticiones por tamaño de matriz
@ejecutables = ("matricesApp");
@matrizSize = ("3", "4", "5", "10", "100", "400", "800", "1000", "2500", "5000");
$path = "/home/yeyaplinux/Documents/Algorithms-master/threads/"; #reemplazar {path} por su ruta donde se encuentra ubicado el proyecto (ej: /home/pedro/paralela/Algorithms/threads/) IMPORTANTE: la ruta debe finalizar en /
$numThreads = 2; #reemplazar {numHilos} por el número de hilos 1, 2, 3, 5, 8, ..., máximo el núcleos que tenga su CPU

foreach $exe (@ejecutables) {
	foreach $size (@matrizSize) {
		$fichero = "$path"."Soluciones/"."$exe"."-size"."$size";
		#print("$fichero\n");
		for ($i=0; $i<$repeticiones; $i++) {
			print("$path$exe $size $numThreads \n"); #sabemos en qué repetición va nuestro proceso
			system("$path$exe $size $numThreads >> $fichero");
		}
	}
}
exit(1);
