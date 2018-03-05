{
    "targets": [
        {
            "target_name": "my_lcd",
            "sources": [
                "obj_one/main.cc"],
            "include_dirs": ["<!(node -e \"require('nan')\")"],
            'libraries': [
                '-L/usr/local/lib', '-lwiringPi'
            ]
        }
    ]
}
