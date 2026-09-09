# Project Governance

This document describes how decisions are made in the **BonoboMock** project.

## Principles
- All decisions are made **openly and transparently** on GitHub.  
- Maintainers act by **consensus**; votes are a fallback.
- Technical merit and respectful collaboration guide every decision.

## Roles
- **Contributors** propose changes through issues or pull requests.  
- **Maintainers** review, approve, and merge contributions, manage releases, and uphold project standards.
- The **Lead Maintainer** coordinates releases and resolves tie votes.  
See [`MAINTAINERS.md`](MAINTAINERS.md) for the current maintainer list.

## Decision-Making
- All proposals and changes are discussed publicly via GitHub issues, pull requests, or discussions.  
- Each pull request requires **two maintainer approvals** (`Approved` reviews) from maintainers other than the author.  
- Minor or low-risk updates may merge with **one approval** if there are no objections.  
- If consensus cannot be reached, maintainers may call for a **majority vote**; the **Lead Maintainer** serves as tiebreaker.

## Merging & Releases
- After approvals and passing CI, any maintainer may merge a pull request.  
- The merging maintainer ensures CI success, documentation and changelog updates, and correct versioning.  
- Releases are tagged, signed, and announced publicly.

## Urgent Fixes
- In emergencies (e.g., broken builds or security issues), a maintainer may merge with **one approval**, followed by **retroactive review** and a note in release documentation.

## Amendments
- Changes to this governance require a pull request with **two maintainer approvals**.
