<?php
/**
 * Configuración básica de WordPress.
 *
 * Este archivo contiene las siguientes configuraciones: ajustes de MySQL, prefijo de tablas,
 * claves secretas, idioma de WordPress y ABSPATH. Para obtener más información,
 * visita la página del Codex{@link http://codex.wordpress.org/Editing_wp-config.php Editing
 * wp-config.php} . Los ajustes de MySQL te los proporcionará tu proveedor de alojamiento web.
 *
 * This file is used by the wp-config.php creation script during the
 * installation. You don't have to use the web site, you can just copy this file
 * to "wp-config.php" and fill in the values.
 *
 * @package WordPress
 */

// ** Ajustes de MySQL. Solicita estos datos a tu proveedor de alojamiento web. ** //
/** El nombre de tu base de datos de WordPress */
define('DB_NAME', 'nombredetubasededatos');

/** Tu nombre de usuario de MySQL */
define('DB_USER', 'nombredeusuario');

/** Tu contraseña de MySQL */
define('DB_PASSWORD', 'contraseña');

/** Host de MySQL (es muy probable que no necesites cambiarlo) */
define('DB_HOST', 'localhost');

/** Codificación de caracteres para la base de datos. */
define('DB_CHARSET', 'utf8');

/** Cotejamiento de la base de datos. No lo modifiques si tienes dudas. */
define('DB_COLLATE', '');

/**#@+
 * Claves únicas de autentificación.
 *
 * Define cada clave secreta con una frase aleatoria distinta.
 * Puedes generarlas usando el {@link https://api.wordpress.org/secret-key/1.1/salt/ servicio de claves secretas de WordPress}
 * Puedes cambiar las claves en cualquier momento para invalidar todas las cookies existentes. Esto forzará a todos los usuarios a volver a hacer login.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         'stkT&WS8^nh5Hr8O!?K.{!EcF2O`goeT:twHt]g)2-(Z/G`%Bvvu6n- kXmA!d=+');
define('SECURE_AUTH_KEY',  '^v-:(_E21{-d0X=Nq4Hj0E|iqtw$<FcK6q1wW*EURr%QvPBVg;Y<6UuMM#/FG,gv');
define('LOGGED_IN_KEY',    '~834R/i?+P=(.qZg^|/_~x>V54xI17G2;t4Bq.65-K= -G?YQ4O&<aV`s+of:t:<');
define('NONCE_KEY',        'q-SqIX5DJG?:<qA:ZIe0~hw#sR,C8u(M>-+!tg^`>+/+MaQtFd^XM:tgRYzCHM%-');
define('AUTH_SALT',        'Xp}^LG)G|H58yQ.P^pSNET+2}Ieodrv.T[k$uS+3&ikP~}a=8`Q6;Pgmh#*O1;-G');
define('SECURE_AUTH_SALT', ',S3p^j9Lo{0al<bP38Hid|_A7L!IfzUhW3%f>lP67Z srt-x9v_Mue6JHeQWBRzY');
define('LOGGED_IN_SALT',   'x/e854brfBVitjZQ([@9GQ1qbK|T-6f&flA6 <PW^>Am!Av wI0XeuMM=k5WWBtL');
define('NONCE_SALT',       '!a-Cv8h-(|d{Vd00I*%/UMw& ) 41`GPWY%0U )*{,zL}IGn+ki3#52NSeXj4#|;');

/**#@-*/

/**
 * Prefijo de la base de datos de WordPress.
 *
 * Cambia el prefijo si deseas instalar multiples blogs en una sola base de datos.
 * Emplea solo números, letras y guión bajo.
 */
$table_prefix = 'wp_';


/**
 * Para desarrolladores: modo debug de WordPress.
 *
 * Cambia esto a true para activar la muestra de avisos durante el desarrollo.
 * Se recomienda encarecidamente a los desarrolladores de temas y plugins que usen WP_DEBUG
 * en sus entornos de desarrollo.
 */
define('WP_DEBUG', false);

/* ¡Eso es todo, deja de editar! Feliz blogging */

/** WordPress absolute path to the Wordpress directory. */
if ( !defined('ABSPATH') )
	define('ABSPATH', dirname(__FILE__) . '/');

/** Sets up WordPress vars and included files. */
require_once(ABSPATH . 'wp-settings.php');

