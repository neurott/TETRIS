# Tetris

Un clon de Tetris hecho en C++ usando [raylib](https://www.raylib.com/) como motor gráfico.

## Características

- Sistema de piezas (bloques) con rotación
- Detección y limpieza de líneas completas
- Efectos de sonido (movimiento, rotación, hard drop, game over) y música de fondo
- Fuente personalizada (Monogram)

## Estructura del proyecto

```
src/        Código fuente (game, grid, block, position, colors, main)
Font/       Fuente utilizada en el juego
Sounds/     Efectos de sonido y música
lib/        Librerías dinámicas necesarias en Windows (libgcc, libstdc++)
Makefile    Build basado en el Makefile de ejemplos de raylib
```

## Requisitos

- [raylib](https://www.raylib.com/) instalado (probado con la versión 5.0.0)
- Un compilador compatible con C++ (MinGW / w64devkit en Windows)

## Compilar

```bash
make
```

Esto genera el ejecutable del juego (`game.exe` en Windows).

## Ejecutar

```bash
./game.exe
```

## Controles

- Flechas izquierda/derecha: mover la pieza
- Flecha abajo: bajar más rápido
- Flecha arriba: rotar
- Barra espaciadora: hard drop

---

> 📝 Este README fue generado con ayuda de IA.
