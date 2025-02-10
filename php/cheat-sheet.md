# PHP Cheatsheet

## Basic Syntax
```php
<?php
    // Your PHP code here
?>
```

## Variables
```php
$string = "Hello World";     // String
$integer = 42;              // Integer
$float = 3.14;             // Float/Double
$boolean = true;           // Boolean
$array = [1, 2, 3];        // Array
$null = null;              // Null value
```

## Constants
```php
define("CONSTANT_NAME", "value");
const MY_CONSTANT = "value";
```

## Arrays
```php
// Indexed array
$fruits = ["apple", "banana", "orange"];

// Associative array
$person = [
    "name" => "John",
    "age" => 30,
    "city" => "New York"
];

// Multidimensional array
$matrix = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
];
```

## Control Structures

### If-Else
```php
if ($condition) {
    // code
} elseif ($another_condition) {
    // code
} else {
    // code
}
```

### Switch
```php
switch ($variable) {
    case 'value1':
        // code
        break;
    case 'value2':
        // code
        break;
    default:
        // code
}
```

### Loops
```php
// For loop
for ($i = 0; $i < 10; $i++) {
    // code
}

// While loop
while ($condition) {
    // code
}

// Do-While loop
do {
    // code
} while ($condition);

// Foreach loop
foreach ($array as $value) {
    // code
}
foreach ($array as $key => $value) {
    // code
}
```

## Functions
```php
// Basic function
function functionName($parameter1, $parameter2 = defaultValue) {
    return $value;
}

// Arrow function (PHP 7.4+)
$multiply = fn($x, $y) => $x * $y;

// Type hints (PHP 7+)
function typedFunction(string $name, int $age): string {
    return "$name is $age years old";
}
```

## String Functions
```php
strlen($string);                   // String length
str_replace($search, $replace, $string);
substr($string, $start, $length);
strtolower($string);
strtoupper($string);
trim($string);
explode($delimiter, $string);      // String to array
implode($delimiter, $array);       // Array to string
```

## Array Functions
```php
count($array);                     // Array length
array_push($array, $value);        // Add to end
array_pop($array);                 // Remove from end
array_shift($array);               // Remove from start
array_unshift($array, $value);     // Add to start
array_merge($array1, $array2);     // Merge arrays
array_keys($array);                // Get all keys
array_values($array);              // Get all values
in_array($needle, $haystack);      // Check if value exists
array_search($needle, $haystack);  // Find value's key
```

## Object-Oriented Programming
```php
class ClassName {
    // Properties
    public $publicVar;
    private $privateVar;
    protected $protectedVar;
    
    // Constructor
    public function __construct($value) {
        $this->publicVar = $value;
    }
    
    // Method
    public function methodName() {
        return $this->publicVar;
    }
}

// Create object
$object = new ClassName("value");

// Inheritance
class Child extends Parent {
    // Override method
    public function methodName() {
        parent::methodName(); // Call parent method
    }
}
```

## Error Handling
```php
try {
    // Code that might throw an exception
} catch (Exception $e) {
    // Handle the exception
    echo $e->getMessage();
} finally {
    // Always executed
}
```

## File Operations
```php
file_get_contents($filename);          // Read file
file_put_contents($filename, $data);   // Write file
fopen($filename, $mode);               // Open file
fclose($handle);                       // Close file
fgets($handle);                        // Read line
fwrite($handle, $string);              // Write to file
file_exists($filename);                // Check if file exists
unlink($filename);                     // Delete file
```

## Database (PDO)
```php
// Connect to database
$pdo = new PDO("mysql:host=$host;dbname=$db", $user, $pass);

// Prepare and execute query
$stmt = $pdo->prepare("SELECT * FROM table WHERE id = ?");
$stmt->execute([$id]);

// Fetch results
$row = $stmt->fetch(PDO::FETCH_ASSOC);
```

## Date and Time
```php
date("Y-m-d H:i:s");                  // Format date
strtotime("2024-02-02");              // String to timestamp
time();                               // Current timestamp
date_default_timezone_set("UTC");     // Set timezone
```

## Superglobals
```php
$_GET       // URL parameters
$_POST      // POST data
$_SESSION   // Session variables
$_COOKIE    // Cookie data
$_FILES     // Uploaded files
$_SERVER    // Server information
$_ENV       // Environment variables
```

## Common Regular Expressions
```php
preg_match($pattern, $string);         // Search pattern
preg_replace($pattern, $replace, $string);
preg_split($pattern, $string);         // Split string
```

## Best Practices
- Always validate and sanitize user input
- Use prepared statements for database queries
- Set error reporting in development only
- Use meaningful variable and function names
- Comment your code appropriately
- Follow PSR coding standards
- Use type hints when possible
- Handle errors gracefully
- Keep functions small and focused
- Use appropriate security measures (password hashing, etc.)