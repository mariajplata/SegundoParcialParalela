# Segundo parcial Computación Paralela: Algoritmos para Comparativa de Rendimiento "Benchmarks - Nodos de Cómputo"

En este repositorio encontrará los siguientes 2 algoritmos para utilizar en el parcial #2 de Computación Paralela y Distribuida:
1. threads: benchmark multiplicación de matrices clásica filas por columnas (Aplicando Paralelismo a Nivel de Threads: POSIX)
2. openmpV3: benchmark multiplicación de matrices clásica filas por columnas (Aplicando Paralelismo a Nivel de Threads: OpenMP)

### Instrucciones de uso y ejecución:

* Al ingresar a cada carpeta de algoritmos, verificar que la carpeta **Soluciones** esté creada y vacía
* Se debe cambiar la ruta (path) para que corresponda a la ubicación de esta carpeta en el computador de cada persona. En el fichero **lanzador.pl** del algoritmo threads en la línea 10 encontrará un comentario al final de esta con instrucciones, el mismo proceso se debe realizar en la línea 11 del algoritmo openmpV3.
**Ejemplo:** si su path es "/home/yeyaplinux/Documents/openmpV3/" debe sustituir la sección posterior a "home/" pero manteniendo siempre al final "openmpV3/" 
* En ambos algoritmos, modifique en el fichero del **lanzador.pl** el número de hilos a utilizar en la ejecución (línea 11 para threads, línea 10 para openmpV3: en este archivo el vector se llama cores pero corresponde al número de hilos).
* Ejecute el lanzador correspondiente del algoritmo. Ej: **./lanzadorEnteros.pl**

### NOTA:
* En el algoritmo de openmpV3 en algunas ocasiones puede arrojar un mensaje de **error de segmentación**, esto generará que en el archivo Soluciones haya algunos espacios en blanco pero no debe deterner el algoritmo en caso de que esto suceda ya que los demás resultados si son guardados correctamente.
* Recuerde que el algoritmo de **threads** lo debe ejecutar la cantidad de veces como la cantidad de hilos que tenga su CPU, modificando en cada ejecución el número de hilos. En openmpV3 no es necesario este proceso ya que lo realiza de forma automática.
