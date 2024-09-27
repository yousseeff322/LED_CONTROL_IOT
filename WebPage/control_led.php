<?php
// Enable error reporting for development
ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);
error_reporting(E_ALL);

// Check if the 'status' POST variable is set
if (isset($_POST['status'])) {
    // Sanitize the input to prevent potential security risks
    $status = filter_input(INPUT_POST, 'status', FILTER_SANITIZE_STRING);
    
    // Open the file for writing (absolute path can be used if needed)
    $file_path = "status.txt";
    $my_file = fopen($file_path, "w");

    // Check if the file was opened successfully
    if ($my_file) {
        // Write the corresponding value based on the status
        switch ($status) {
            case 'on':
                fwrite($my_file, '1'); // Turn LED on
                break;
            case 'off':
                fwrite($my_file, '0'); // Turn LED off
                break;
            case 'animation1':
                fwrite($my_file, '2'); // Animation 1
                break;
            case 'animation2':
                fwrite($my_file, '3'); // Animation 2
                break;
            case 'animation3':
                fwrite($my_file, '4'); // Animation 3
                break;
            default:
                echo "Error: Invalid status.";
                fclose($my_file);
                exit();
        }
        
        // Close the file and return success message
        fclose($my_file);
        echo "Success: Status updated.";
    } else {
        // File opening failed
        echo "Error: Unable to open file.";
    }
} else {
    // 'status' POST variable not set
    echo "Error: Status not set.";
}
?>
