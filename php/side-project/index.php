<?php 
    include("database.php");
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>register</title>
</head>
<body>
    <form action="<?php htmlspecialchars($_SERVER["PHP_SELF"]) ?>" method="post">
        <label for="username">username :<br></label>
        <input type="text" name="username"><br>
        <label for="email">email :<br></label>
        <input type="email" name="email"><br>
        <label for="password">password :<br></label>
        <input type="password" name="password"><br>
        <label for="sexe">sexe :<br></label>
        <input type="radio" name="sexe" value="Homme"> Homme <br>
        <input type="radio" name="sexe" value="Femme"> Femme <br>
        <input type="submit" name="register" value="register"><br>
    </form>
    
</body>
</html>

<?php
    
    if($_SERVER["REQUEST_METHOD"] == "POST"){

        $username = filter_input(INPUT_POST,"username",FILTER_SANITIZE_SPECIAL_CHARS);
        $password = filter_input(INPUT_POST,"password",FILTER_SANITIZE_SPECIAL_CHARS);
        $email = filter_input(INPUT_POST,"email",FILTER_SANITIZE_EMAIL);
        $sexe = filter_input(INPUT_POST,"sexe",FILTER_SANITIZE_SPECIAL_CHARS);
        
        if(empty($username) || empty($password) || empty($email) || empty($sexe)){
            echo"<h3>Un champs est vide !</h3>";
        }
        else{
            try{
                $hash = password_hash($password, PASSWORD_DEFAULT);
                $insert_user = "INSERT INTO users (user, password, email , sexe)
                                VALUES('$username', '$hash', '$email', '$sexe')";
                mysqli_query($connection,$insert_user);
                echo"Welcome {$username}";
            }
            catch(mysqli_sql_exception){
                echo"user or email already exists !";
            }
            
        }
        
    }

    mysqli_close($connection);
?>