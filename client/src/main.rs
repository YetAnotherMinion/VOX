#[macro_use]
extern crate glium;

// we use the image crate to decode the image format that stores our texture
extern crate image;

mod teapot;
// We want to create a window with an OpenGL context handled by glium, instead
// of calling `build()` we will call `build_glium()` which is defined  in the
// `glium::DisplayBuild` trait
use glium::DisplayBuild;
// to fill a `Frame` with color we need to import `Surface` trait
use glium::Surface;

use std::path::Path;
use std::fs::File;
use std::borrow::Borrow;

#[derive(Copy, Clone)]
struct ArbitraryNameVertex {
    position: [f32; 2],
    tex_coords: [f32; 2],
}

implement_vertex!(ArbitraryNameVertex, position, tex_coords);

fn load_glsl_resource(path: &Path) -> String {
    use std::io::{Read, Write, stdout};
    use std::error::Error;

    let mut file = match File::open(path) {
        // The `description` method of io::Error returns a string that
        // describes the error
        Err(why) => panic!("could not read {}: {}", path.display(),
                                                    why.description()),
        Ok(f) => f,
    };
    
    let mut buffer = String::new();
    let bytes_read = match file.read_to_string(&mut buffer) {
        Ok(bytes) => bytes,
        Err(err) => panic!("could not read for files"),
    };
  
    //println!("Bytes read: {}", bytes_read);

    //println!("Buffer contents:\n{}", buffer);
    //stdout().flush();
    buffer
}

fn load_texture(path: &Path) -> Vec<u8> {
    use std::io::{Read, Write, stdout};
    use std::error::Error;

    let mut file = match File::open(path) {
        // The `description` method of io::Error returns a string that
        // describes the error
        Err(why) => panic!("could not read {}: {}", path.display(),
                                                    why.description()),
        Ok(f) => f,
    };
    
    let mut buffer = Vec::<u8>::new();
    let bytes_read = match file.read_to_end(&mut buffer) {
        Ok(bytes) => bytes,
        Err(err) => panic!("could not read for files"),
    };
  
    //println!("Bytes read: {}", bytes_read);

    //println!("Buffer contents:\n{}", buffer);
    //stdout().flush();
    buffer
}
fn main() {
    let display = glium::glutin::WindowBuilder::new().build_glium().unwrap();
        
    let vertex1 = ArbitraryNameVertex { position: [-0.5, -0.5],
                                        tex_coords: [0.0, 0.0] };
    let vertex2 = ArbitraryNameVertex { position: [0.0, 0.5],
                                        tex_coords: [0.0, 1.0] };
    let vertex3 = ArbitraryNameVertex { position: [0.5, -0.25],
                                        tex_coords: [1.0, 0.0] };

    let shape = vec![ vertex1, vertex2, vertex3];
    let vertex_buffer = glium::VertexBuffer::new(&display, &shape).unwrap();
    
    let mut t: f32 = -0.5;

    let vertex_shader_path = Path::new("./src/example_1.vert");
    let frag_shader_path = Path::new("./src/example_1.frag");
    let texture_path = Path::new("./src/example_1.png");
    // kick the can about handling a loading error down the road
    let vertex_shader_src = load_glsl_resource(&vertex_shader_path);
    let fragment_shader_src = load_glsl_resource(&frag_shader_path);

    use std::io::Cursor;
    let image = image::load(Cursor::new(load_texture(&texture_path)),
                            image::PNG).unwrap().to_rgba();
    let image_dimensions = image.dimensions();
    let image = glium::texture::RawImage2d::from_raw_rgba_reversed(image.into_raw(), image_dimensions);

    let texture = glium::texture::Texture2d::new(&display, image).unwrap();

    // prevent the window from immediately closing by polling forever until we
    // recieve a `Closed` event
    loop {
        t += 0.02;
        if t > 0.5 {
            t = -0.5;
        }

        let uniforms = uniform! {
            matrix: [
                [1.0, 0.0, 0.0, 0.0 ],
                [0.0, 1.0, 0.0, 0.0 ],
                [0.0, 0.0, 1.0, 0.0 ],
                [t, 0.0, 0.0, 1.0f32 ],
            ],
            tex: &texture,
        };
        // draw a test image
        let mut target = display.draw();
        target.clear_color(0.0, 0.0, 1.0, 1.0);

        let indicies = glium::index::NoIndices(glium::index::PrimitiveType::TrianglesList);
        
        let program = glium::Program::from_source(&display,
                                                  vertex_shader_src.borrow(),
                                                  fragment_shader_src.borrow(),
                                                  None).unwrap();

        target.draw(&vertex_buffer, &indicies, &program,
                    &uniforms,
                    &Default::default()).unwrap();
        target.finish().unwrap();


        for ev in display.poll_events() {
            match ev {
                glium::glutin::Event::Closed => return, // window closed by user
                _ => (),
            }
        }
    }
}
