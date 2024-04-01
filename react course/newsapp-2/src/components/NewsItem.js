import React, { Component } from 'react'

export class NewsItem extends Component {

    render() {
        let { title, description, imageUrl, newsUrl, author, date, source } = this.props;
        return (
            <div className='my-3'>
                <div className="card" style={{ width: "18rem" }}>
                    <span className="position-absolute top-0 translate-middle badge rounded-pill bg-danger" style={{left:'90%', zIndex:'1'}}>{source}
                    </span>
                    <img src={imageUrl ? imageUrl : "https://cdn.vox-cdn.com/thumbor/K65V2wS5Rarg8tP808XKRiVRyAA=/0x350:9128x5129/fit-in/1200x630/cdn.vox-cdn.com/uploads/chorus_asset/file/25359520/GettyImages_1533302708.jpg"} className="card-img-top" alt="..." />
                    <div className="card-body">
                        <h5 className="card-title">{title}...

                        </h5>
                        <p className="card-text">{description}...</p>
                        <a rel="noreferrer" href={newsUrl} target="_blank" className="btn btn-sm btn-dark">Read More</a>
                        <p className="card-text"><small className="text-body-secondary">By {author} on {date}.</small></p>

                    </div>
                </div>
            </div>
        )
    }
}

export default NewsItem