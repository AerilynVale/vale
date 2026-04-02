#!/usr/bin/env python3
import sys

def convert_hex_to_bin(input_path, output_path):
    font_data = bytearray(256 * 16)

    try:
        with open(input_path, 'r') as f:
            for line in f:
                line = line.strip()
                if not line:
                    continue
                
                parts = line.split(':')
                if len(parts) != 2:
                    continue
                
                char_code = int(parts[0], 16)
                
                if char_code < 256:
                    bitmap_hex = parts[1]
                    if len(bitmap_hex) == 32:
                        bitmap_bytes = bytes.fromhex(bitmap_hex)
                        start_index = char_code * 16
                        font_data[start_index:start_index+16] = bitmap_bytes

        with open(output_path, 'wb') as f:
            f.write(font_data)
            
    except FileNotFoundError:
        print(f"Error: Could not find {input_path}")
        sys.exit(2)

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: hex2bin.py <input.hex> <output.bin>")
        sys.exit(22)

    convert_hex_to_bin(sys.argv[1], sys.argv[2])