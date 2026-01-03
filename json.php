<?php
header("Content-Type: application/json");

// Sample data
$posts = [
    ["id" => 1, "title" => "Post 1"],
    ["id" => 2, "title" => "Post 2"],
    ["id" => 3, "title" => "Post 3"]
];

// Get ID from URL: json.php/1
$request = $_SERVER['REQUEST_URI'];
$parts = explode('/', trim($request, '/'));

// Get last part as ID
$id = end($parts);

// If ID is numeric → return single post
if (is_numeric($id)) {
    foreach ($posts as $post) {
        if ($post['id'] == $id) {
            echo json_encode($post, JSON_PRETTY_PRINT);
            exit;
        }
    }

    // If ID not found
    http_response_code(404);
    echo json_encode(["error" => "Post not found"]);
    exit;
}

// If no ID → return all posts
echo json_encode($posts, JSON_PRETTY_PRINT);
