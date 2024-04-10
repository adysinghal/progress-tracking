import React from 'react'

const Noteitem = (props) => {
    const { note } = props;
    return (
        <div className='col-md-3'>
            <div class="card">
                <div class="card-body">
                    <div className="d-flex align-items-center">
                        <h5 class="card-title">{note.title}</h5>
                        <i class="fa-solid fa-trash mx-2"></i>
                        <i class="fa-regular fa-pen-to-square mx-2"></i>
                    </div>
                    <p class="card-text">{note.description}</p>
                </div>
            </div>
        </div>
    )
}

export default Noteitem