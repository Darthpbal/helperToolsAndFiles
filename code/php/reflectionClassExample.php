<?php
$reflector = new ReflectionClass('PDO');
var_dump($reflector->getConstants());
