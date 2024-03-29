# ESE_GRS v3.2.1 

Este proyecto tiene como objetivo el desarrollo de una aplicaci�n
para simular el movimiento del brazo ESE_GRS de 6 articulaciones y 
generar superficies complejas utilizando planos y superficies a partir 
de puntos, l�neas y curvas con un acabado final en el editor 3D Autodesk 
Inventor. Puede vincularse con el [ESE_GRSConnectionSimulator](https://github.com/Esteban1914/ESE_GRS_ConnectionSimulator)
para usar otros servicios.


## [Descargar ESE_GRS](https://github.com/Esteban1914/ESE_GRS/raw/master/media/ESE_GRS/ESE_GRS.rar)

![Foto de ESE_GRS](https://github.com/Esteban1914/ESE_GRS/blob/master/media/ESE_GRS.png)
![Foto de ESE_GRS](https://github.com/Esteban1914/ESE_GRS/blob/master/media/ESE_GRS1.png)


## Plataforma
>WindowsX64

## Lenguaje
>C++ 

## Librerias utilizadas
> - OpenGL(Simular el brazo en un entorno 3D)
> - winsock(Conexiones por Sockets)
> - libxl(Comunicaci�n de la Aplicacion con Autodesk Inventor)

## Conexiones
> - Puerto Serie
> - Sockets(Eternet y Wifi)

## Sobre los desarrolladores
>***Creaci�n y mantenimiento del brazo f�sico:***
> - Telegram:  @ACB273
>
>***Comunicaci�n arduino PC y desarrollo de la aplicaci�n:***
> - Telegram:  @EstebanACB2
> - Correo:    acevedoesteban999@gmail.com

***Importante para el desarrollo en Visual Studio 2012***
> 1. Configuration Properites->General->characterSet=Not Set
> 2. Configuration Properites->General->Common Language Runtime Support=No Common Language Runtime Support
> 3. C/C++->General->Additional Include Directories=.../libxl/include_cpp && .../freeglut/include
> 4. Linker->General->Additional Library Directories=.../freegut/lib/ && .../xlms/lib/)
> 5. Linker->Input->Additinal Dependencies=freeglut.lib && libxl.lib